import assert from 'assert';
import handler from 'serve-handler';
import http from 'http';

import { Builder, By, Key, until, Browser } from 'selenium-webdriver';
import chrome from 'selenium-webdriver/chrome.js';
import edge from 'selenium-webdriver/edge.js';
import firefox from 'selenium-webdriver/firefox.js';
import ie  from 'selenium-webdriver/ie.js';
import safari from 'selenium-webdriver/safari.js';
import opera from 'selenium-webdriver/opera.js';

function get_first_available_browser() {
    if (chrome.locateSynchronously()) {
        return Browser.CHROME;
    } else if (edge.locateSynchronously()) {
        return Browser.EDGE;
    } else if (firefox.locateSynchronously()) {
        return Browser.FIREFOX;
    } else if (safari.locateSynchronously()) {
        return Browser.SAFARI;
    } else if (opera.locateSynchronously()) {
        return Browser.OPERA;
    } else if (ie.locateSynchronously()) {
        return Browser.IE;
    } else {
        throw 'Cannot find Selenium driver for any browser';
    }
}

describe('Web App', function () {
    before(function() {
        let browser_name = get_first_available_browser();
        this.driver = new Builder().forBrowser(browser_name).build();

        this.server = http.createServer((request, response) => {
            return handler(request, response);
        });
        this.server.listen(5000, () => {});
    });

    after(function() {
        this.driver.quit();
        this.server.close();
    });

    it('should have a proper ui', async function() {
        let driver = this.driver;
        this.timeout(60000); // Give the test case 1 minute.

        try {
            await driver.get('http://localhost:5000');

            let value_input_ele = await driver.wait(until.elementLocated(By.css('#value')), 5000);
            let btn = await driver.wait(until.elementLocated(By.css('#calculate-btn')), 5000);
        } finally {}
    });

    it('should show the result when click on the button', async function() {
        let driver = this.driver;
        this.timeout(60000);

        try {
            await driver.get('http://localhost:5000');

            let value_input_ele = await driver.wait(until.elementLocated(By.css('#value')), 5000);
            let btn = await driver.wait(until.elementLocated(By.css('#calculate-btn')), 5000);
            let result_ele = await driver.wait(until.elementLocated(By.css('#result')), 5000);


            await btn.click();
            assert.equal("8", await result_ele.getAttribute('textContent'));

        } finally {}
    });
});
