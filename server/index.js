const express = require("express");
const app = express();

//routes

const potRoutes = require('./routes/potAPI')
const webRoutes = require('./routes/web')

app.use(webRoutes)
app.use('/api/', potRoutes)

//middlewares

const morgan = require("morgan");

app.use(morgan("dev"));
app.use(express.json())

app.listen(3000, ()=>{
    console.log("Servidor corriendo en el puerto 3000");
});