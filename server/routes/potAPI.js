const router = require('express').Router()

router.post('/signin', function(req, res) {
    console.log(req.body);
});

router.get('/getdata',function(req, res) {
    console.log(req.body);
});

module.exports = router