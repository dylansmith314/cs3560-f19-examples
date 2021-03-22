# Unit Testing Example in JavaScript

This uses the ECMAScript module system for the code under test. Mocha is used
as the test framework.

## Requirements

Install Node.js version greater than 13.2.0. Then run `npm install` in this folder to install packages. You will also need selenium driver for a browser that is available on your system.

## Run the test cases

To run the unit test cases, run `npm run test`. To run the selenium test cases, run `npm run test-browser`.

## Run the web application

Run `npm run serve`, and visit the http://localhost:5000 (or the URL in the output). Note that
if you open index.html file in the browser by itself, you will get the CORS error.

## Links

### Articles

These are the resources that are used during the development of this example:

- EMCAScript module system (why we need Node version that is greater than 13.20.0, and the `.mjs` extension) [https://nodejs.org/api/esm.html#esm_modules_ecmascript_modules](https://nodejs.org/api/esm.html#esm_modules_ecmascript_modules)
- Selenium example [https://www.npmjs.com/package/selenium-webdriver#usage](https://www.npmjs.com/package/selenium-webdriver#usage)
- Using Selenium with Mocha [https://blog.testproject.io/2017/06/07/javascript-testing-with-selenium-webdriver-mocha/](https://blog.testproject.io/2017/06/07/javascript-testing-with-selenium-webdriver-mocha/)
- Mocha async/await [https://mochajs.org/#using-async-await](https://mochajs.org/#using-async-await)
- Using serve during test case via API [https://www.npmjs.com/package/serve#api](https://www.npmjs.com/package/serve#api)

## Tutorial

This section will discuss how to create this example from scratch.

After installing all the requirement, create a folder to store all the files and create `index.html` with the following content.

```html
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
        <title>Fibonacci</title>
        <script type="module" src="main.js"></script>
    </head>
    <body>
        <div id="container">
            <h2>Fibonacci Calculator</h2>
            <label for="value">N:</label>
            <input id="value" name="value" type="text" value="6"></input>
            <button id="calculate-btn">Calculate</button>
            <p id="result"></p>
        </div>
    </body>
</html>
```

The most important parts are the input tag, button tag, and the p tag. These define the text box for the input, the button and the space for displaying the result respectively.

You can open this file in a browser and it should display something similar to this.

IMAGE

If you try to interact with it, nothing will happen. If you open the console of the developer tool (SEE: HOW TO OPEN DEV TOOL), you will see an error that the `main.js` cannot be loaded.

Next we will write the function to calculate Fibonacci number. Begin by running `npm init`, it will ask you several questions, most of them should be easy to answer. If you are not sure, you can leave them blank.

With all questions answered, it will ask you to confirm. By answering no you can revise your answer. It will create a file named `package.json`. It should look similar to this one.

```json
{
  "name": "cs3560-unit-testing-example",
  "version": "1.0.0",
  "description": "Example of unit testing in JavaScript",
  "main": "main.js",
  "scripts": {
    "test": "echo \"Error: no test specified\" && exit 1"
  },
  "author": "",
  "license": "ISC"
}
```

To begin writing our function, we can create a folder named `modules`, and a file `fib.mjs` inside it. In this file we can write our function:

```javascript
function fib(n) {
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
```

This is just a typical iterative version of the Fibonacci function. However, we cannot use this function outside the file. We need to export it by adding `export default`. The file should end up like this:

```javascript
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
```

Let try to use this function. Open Node.js REPL by running `node` in your terminal. You will see the following prompt (the version may be different):

```shell
Welcome to Node.js v14.15.3.
Type ".help" for more information.
> let fib;
undefined
> import('./modules/fib.mjs').then(module => { fib = module.default });
Promise { <pending> }
> fib(6);
8
>
```

First we defined a variable fib for our function with `let fib;`. Then we use dynamic import to import our function. After that we can call the function normally. To exit, you can type `process.exit()` on an empty prompt and hit enter.

Since we are going to use Mocha as the test framework, let install it with `npm install --save-dev mocha`. The `--save-dev` will add one more section to the `package.json`, the newly added section is:

```json
  "devDependencies": {
    "mocha": "^8.2.1"
  }
```

To write a test case, make a directory name `test`, and create a new file `test.mjs` in this directory. We can start by importing necessary libraries:

```javascript
import assert from 'assert';
import fib from '../modules/fib.mjs';
```

The first one is the assert library. This provides functions that can be used to test our function. The second one is our Fibonacci library. On the next line after that we can define the test suite by write out:

```javascript
describe('Fib Module', function() {
    // ... more code will goes here.
}
```

This defines the test suite, which is a collection of test cases. The first argument is the name of the test suite. The second argument is the function that will be run when the test suite is run.

Within the test suite we can add couple of test cases.

```javascript
describe('Fib Module', function() {
    it('should return 1 for n equals to 1 or 2', function() {
        assert.equal(fib(1), 1);
        assert.equal(fib(2), 1);
    });
    it('should return correct number for n grater than 2', function() {
        assert.equal(fib(3), 2);
        assert.equal(fib(6), 8);
    });
}
```

Test case is specified by `it(description, function);`. From the first one, 
