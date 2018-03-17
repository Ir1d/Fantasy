var my = require('./b.js');
var loc = process.argv[2];
var tp = process.argv[3];

my(loc, tp, function(err, data) {
  if (err) {
    return console.error(err);
  }
  data.forEach(function(x) {
    console.log(x);
  });
});