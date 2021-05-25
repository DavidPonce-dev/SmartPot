const { Schema, model } = require('mongoose')

const potDataSchema = new Schema({
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
    pot:{
        type: Schema.Types.ObjectId,
        ref: 'PotSchema'
    },
})

module.exports = model('PotDataSchema', potDataSchema)  