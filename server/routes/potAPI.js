const router = require('express').Router()
const bodyParser = require('body-parser')

router.post('/signin', bodyParser.json(), function(req, res) {
    console.log(req.body);
});

router.post('/getdata', bodyParser.json(), function(req, res) {
    console.log(req.body);
});

module.exports = router