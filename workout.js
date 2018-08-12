var express = require('express');
var bodyParser = require('body-parser');
var mysql = require('mysql');
var pool = mysql.createPool({
  connectionlimit : 10,
  host            : 'localhost',
  user            : 'student',
  password        : 'default',
  database        : 'student'
});


var app = express();
var handlebars = require('express-handlebars').create({defaultLayout:'main'});

app.engine('handlebars', handlebars.engine);
app.set('view engine', 'handlebars');
app.set('port, 8376');/*double check this one */
app.use(bodyParser.urlencoded({extended: false}));
app.use(bodyParser.json());
app.use(express.static('public'));



app.get('/reset-table',function(req,res,next){
  var context = {};
  pool.query("DROP TABLE IF EXISTS workouts", function(err){
    var createString = "CREATE TABLE workouts("+
    "id INT PRIMARY KEY AUTO_INCREMENT,"+
    "name VARCHAR(255) NOT NULL,"+
    "reps INT,"+
    "weight INT,"+
    "date DATE,"+
    "lbs BOOLEAN)";
    mysql.pool.query(createString, function(err){
      context.results = "Table reset";
      res.render('home',context);
    })
  });
});

app.get('/insert', function(req, res, next){
  var context = {};
  pool.query("INSERT INTO workouts ('name', 'reps', 'weight', 'date', 'lbs') VALUES (?,?,?,?,?)", [req.query.name, req.query.reps, req.query.weight, req.query.date, req.query.lbs], function(err, result)
  {
  if(err){
    next(err);
    return;
  }
  context.results = "Inserted id " + result.insertID;
  res.render('home', context);
  })
});

app.get('/getWorkout', function (req, res){
  var content = {};
  pool.query('SELECT * FROM workouts WHERE id=?', [req.query.id], function(err, rows, fields){
    if(err){
      next(err);
      return;
    }
    context.results = JSON.stringify(rows);
    res.render('home', context);
  });
});

app.get('/showWorkouts', function(req, res){
  var content = {};
  pool.query('SELECT * FROM workouts', function(err, rows, fields){
    if(err){
      next(err);
      return;
    }
    context.results = JSON.stringify(rows);
    res.render('home', context);
  });
});

app.get('/updateWorkout', function(req, res, next){
  var context = {};
  pool.query('SELECT * FROM workouts WHERE id=?', [req.query.id], function(err, result){
    if (err){
      next(err);
      return;
    }
    if(result.length == 1){
      var curVals = result[0];
      pool.query("UPDATE workouts SET name=?, reps=?, weight=?, date=?, lbs=? WHERE id=?", [req.query.name || curVals.name, req.query.reps || curVals.reps, req.query.weight || curVals.weight, req.query.date || curVals.date, req.query.lbs || curVals.lbs, req.query.id],
    function(err, result){
      if(err){
        next(err);
        return;
      }
      context.results = "Updated " + result.changedRows + " rows.";
      res.render('home', context);
    });
    }
  });
});

app.get('/delete', function(req, res, next){
  var context = {};
  pool.query("DELETE FROM workouts WHERE id=?", [req.query.id], function(err, result){
    if(err){
      next(err);
      return;
    }
    context.results = "Deleted " + result.changedRows + " rows.";
    res.render('home', context);
  });
});
