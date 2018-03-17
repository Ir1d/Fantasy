var http = require('http');
var async = require('async');
var bl = require('bl');

let url = [];
// console.log(process.argv);
for (let i = 2; i < 5; ++i) url.push(process.argv[i]);

async.series([
    function(callback) {
        http.get(url[0], function(res) {
    res.setEncoding('utf8');
    res.pipe(bl(function(err, data) {
    if (err) console.error(err);
      // console.log(data.length);
      console.log(data.toString());
    }));
}).on('error', console.error);
        callback(null, 'one');
    },
    function(callback) {
        http.get(url[1], function(res) {
    res.setEncoding('utf8');
    res.pipe(bl(function(err, data) {
    if (err) console.error(err);
      // console.log(data.length);
      console.log(data.toString());
    }));
}).on('error', console.error);
        callback(null, 'two');
    },
        function(callback) {
        http.get(url[2], function(res) {
    res.setEncoding('utf8');
    res.pipe(bl(function(err, data) {
    if (err) console.error(err);
      // console.log(data.length);
      console.log(data.toString());
    }));
}).on('error', console.error);
        callback(null, 'two');
    }
],
// optional callback
function(err, results) {
    // results is now equal to ['one', 'two']
});
// async.eachOfSeries(url, (v, cb) => {
//   http.get(v, function(res) {
//     res.setEncoding('utf8');
//     res.pipe(bl(function(err, data) {
//     if (err) console.error(err);
//       // console.log(data.length);
//       console.log(data.toString());
//     }));
// }).on('error', console.error);
// });
