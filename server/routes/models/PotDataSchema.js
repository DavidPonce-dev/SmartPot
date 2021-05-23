const { Schema, model } = require('mongoose')

const potDataSchema = new Schema({
    _id: Number,

    waterLvl: {
        type: Number,
        required: true
    },
    density: {
        type: Number,
        required: true
    },
    waterPh: {
        type: Number,
        required: true
    },
})

module.exports = model('PotDataSchema', potDataSchema)  