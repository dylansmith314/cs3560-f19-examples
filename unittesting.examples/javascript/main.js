import fib from './modules/fib.mjs';

window.onload = function () {
    let calculate_btn = document.getElementById('calculate-btn');
    let value_input = document.getElementById('value');
    let result_ele = document.getElementById('result');

    let calc = (e) => {
        let value = parseInt(value_input.value);
        let result = fib(value);
        result_ele.textContent = result;
    };

    value_input.addEventListener('keypress', (e) => {
        if (e.key === 'Enter') {
            calc(e);
        }
    });
    calculate_btn.addEventListener('click', calc);
};
