const router = require('express').Router()
const bodyParser = require('body-parser')

router.post('/login', bodyParser.json(), function(req, res) {
    console.log(req.body);
});
router.post('/register', bodyParser.json(), function(req, res) {
    console.log(req.body);
    res.send({apiKey:"recibido"});
});

module.exports = router