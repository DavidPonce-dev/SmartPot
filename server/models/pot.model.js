const { Schema, model } = require('mongoose')

const potSchema = new Schema({
    chipID: {
        type: String,
        required: true
    },
    name: {
        type: String,
        required: true
    },
    data:[{
        type: Schema.Types.ObjectId,
        ref: 'PotDataSchema'
    }]
})

module.exports = model('PotSchema', potSchema)