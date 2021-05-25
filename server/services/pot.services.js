const potModel = require("../models/pot.model")

exports.createPot = async potInfo => {
    const pot = new potModel({...potInfo})
    return await pot.save()
}

exports.addData = async (potId, data) => {
    const pot = await potModel.findById(potId).exec();
    pot.data.push(data)
    await pot.save()
}