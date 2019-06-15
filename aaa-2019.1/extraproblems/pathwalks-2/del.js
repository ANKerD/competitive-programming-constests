const http = require('http');

http.createServer((req, res) => {
    console.log("hi");
    res.write("hello phone");
    res.end();
}).listen(8080);