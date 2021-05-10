const express = require("express");
const app = express();

app.get('/', function(req, res) {
    res.send('Hola mundo!');
});
app.get('/login', function(req, res) {
    res.send('pagina de login!');
});
app.get('/register', function(req, res) {
    res.send('Pagina de registro!');
});

app.listen(3000, ()=>{
    console.log("Servidor corriendo en el puerto 3000");
});