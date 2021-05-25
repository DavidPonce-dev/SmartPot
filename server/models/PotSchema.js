const { Schema, model } = require('mongoose')

const potSchema = new Schema({
    _id: Number,

    chipID: {
        type: String,
        required: true
    },

    apiKey: {
        type: String,
        required: true
    },
    data:[{
        type: Schema.Types.ObjectId,
        ref: 'PotDataSchema'
    }]
})

module.exports = model('PotSchema', potSchema)  