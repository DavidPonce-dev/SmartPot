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
    pot:{
        type: Schema.Types.ObjectId,
        ref: 'PotData'
    },
})

module.exports = model('PotDataSchema', potDataSchema)  