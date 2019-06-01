// ==UserScript==
// @name         洛谷防抄题解
// @namespace    https://tony031218.github.io/
// @version      0.1
// @description  五秒钟后关掉题解页面
// @author       Tony_Wong
// @match        https://www.luogu.org/problemnew/solution/*
// @grant        none
// ==/UserScript==

(function() {
    'use strict';
    alert("5秒后即将关闭");
    setTimeout(function(){window.close()}, 5000);
})();