#!/usr/bin/env node
var execFile = require('child_process').execFile;
var zonename = require('../lib');

var time;

time = process.hrtime();
zonename();
printTime('zonename()       ', process.hrtime(time));

time = process.hrtime();
execFile('zonename', [], {encoding: 'utf8'}, function (err, stdout, stderr) {
    if (err)
        throw err;
    printTime('execFile zonename', process.hrtime(time));
});

function printTime(msg, hr) {
    var ns = '' + hr[1];
    while (ns.length < 9)
        ns = '0' + ns;
    console.log('%s %s.%s seconds', msg, hr[0], ns);
}
