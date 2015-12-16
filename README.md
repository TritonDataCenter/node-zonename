node-zonename
=============

Get the current zonename

Usage
-----

### `zonename()`

Returns a string that represents the current zones name.

Example
-------

``` js
var zonename = require('zonename');
var me = zonename();
// => "global"
```

Benchmark
---------

Simple benchmark to show this native module vs fork+exec of `zonename(1)`

```
$ ./benchmark/benchmark.js
zonename()        0.000098533 seconds
execFile zonename 0.032777991 seconds
```

License
-------

MPL 2.0
