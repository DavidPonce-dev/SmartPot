const { Schema, model } = require('mongoose')

const potSchema = new Schema({
    chipID: {
        type: String,
        required: true
    },
    apiKey: {
        type: String,
        required: true
    },
})

module.exports = model('PotSchema', potSchema)  