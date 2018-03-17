var fs = require('fs');
var loc = process.argv[2];
var s = fs.readFileSync(loc).toString();
console.log(s.split('\n').length - 1)