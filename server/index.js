const express = require("express");
const app = express();

//routes

const potRoutes = require('./routes/potAPI')
const webRoutes = require('./routes/web')

app.use(webRoutes)
app.use('/api/pot/', express.json(), express.urlencoded() , potRoutes)

//middlewares

app.use(require("morgan")("dev"));

//listener

const main = async () => {
    try {
        //await require("./db");
        console.log("DB iniciada");
        app.listen(3000, ()=>{
            console.log("Servidor corriendo en el puerto 3000");
        });
        const potService = require("./services/pot.services")
        potService.createPot({
              chipID: "asdasd",
              name: "Macetaza",
              key:"LLAve",
        })

    } catch (error) {
        console.error(error)
    }
}
main();