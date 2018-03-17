var http = require('http');
var url = require('url');
var express = require('express');
var app = express();

app.get('/api/parsetime', (req, res) => {
  var s = req.query.iso;
  // console.log(s);
  s = s.split('T')[1].split('.')[0].split(':');
  // console.log(s);
  var data = {};
  data['hour'] = (Number(s[0]) + 8) % 24;
  data['minute'] = Number(s[1]);
  data['second'] = Number(s[2]);
  res.end(JSON.stringify(data));
});

app.get('/api/unixtime', (req, res) => {
  var s = req.query.iso;
  var d = new Date(s);
  d = d.getTime();
  console.log(d);
  // s = s.split('T')[1].split('.')[0].split(':');
  // console.log(s);
  var data = {};
  data['unixtime'] = d;
  res.end(JSON.stringify(data));
});

app.listen(Number(process.argv[2]), () => console.log(`Example app listening on port ${Number(process.argv[2])}!`))

/*

    var http = require('http')
    var url = require('url')
    
    function parsetime (time) {
      return {
        hour: time.getHours(),
        minute: time.getMinutes(),
        second: time.getSeconds()
      }
    }
    
    function unixtime (time) {
      return { unixtime: time.getTime() }
    }
    
    var server = http.createServer(function (req, res) {
      var parsedUrl = url.parse(req.url, true)
      var time = new Date(parsedUrl.query.iso)
      var result
    
      if (/^\/api\/parsetime/.test(req.url)) {
        result = parsetime(time)
      } else if (/^\/api\/unixtime/.test(req.url)) {
        result = unixtime(time)
      }
    
      if (result) {
        res.writeHead(200, { 'Content-Type': 'application/json' })
        res.end(JSON.stringify(result))
      } else {
        res.writeHead(404)
        res.end()
      }
    })
    server.listen(Number(process.argv[2]))

 */