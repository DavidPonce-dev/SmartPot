const router = require('express').Router()

router.get('/', function(req, res) {
    res.send('Hola mundo!');
});
router.get('/login', function(req, res) {
    res.send('pagina de login!');
});
router.get('/register', function(req, res) {
    res.send('Pagina de registro!');
});

module.exports = router