var fs = require('fs');
var loc = process.argv[2];
var tp = '.' + process.argv[3];
fs.readdir(loc, function(err, data) {
  if (err) {
    console.error(err);
    return;
  }
  data.forEach(function(x) {
    if (x.endsWith(tp)) console.log(x);
  });
});