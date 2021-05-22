const mongoose = require("mongoose")

const username = 'admin'
const password = 'admin'
const database = 'smart-pot'

const uri = `mongodb+srv://${username}:` +
						`${password}@cluster0.a8g4r.mongodb.net/` +
						`${database}?retryWrites=true&w=majority&ssl=true`
                        


const run  = () =>{
  mongoose.connection.on('error', console.error.bind(console, 'connection error:'));

  return mongoose.connect(uri, {
      useNewUrlParser: true,
      useUnifiedTopology: true,
    });
}

module.exports = run();
