var fs = require('fs');
module.exports = function(loc, tp, cb) {
  fs.readdir(loc, 'utf-8', function(err, data) {
    if (err) {
      return cb(err);
    }
    tp = '.' + tp;
    /*
    let res = data.filter(function(x) {
      return path.extname(x) === '.' + tp;
    });
     */
    let res = []
    data.forEach(function(x) {
      if (x.endsWith(tp)) {
        res.push(x);
      }
    });
    cb(null, res);
  });
}
