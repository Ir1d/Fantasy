var net = require('net');
var strftime = require('strftime');

var server = net.createServer((socket) => {
  var data = new Date();
  socket.write(strftime('%Y-%m-%d %R\n', data));
  socket.end();
  // socket.end(strftime('%Y-%m-%d %R', data));
  // console.log();
});
server.listen(Number(process.argv[2]));
