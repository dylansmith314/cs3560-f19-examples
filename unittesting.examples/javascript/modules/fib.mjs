// A Fibonacci function.
//
// This is in a separate file so that it can be included in the HTML file
// and can be imported into the test cases.
export default function fib(n) {
    var a = 0;
    var b = 1;

    var i = 0;
    while (i < n) {
        var tmp = b;
        b = a + b;
        a = tmp;
        i += 1;
    }
    return a;
}
