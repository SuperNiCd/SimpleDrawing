local app = app
local libPassThru = require "PassThru.libPassThru"
local Class = require "Base.Class"
local Unit = require "Unit"
local Encoder = require "Encoder"
local GainBias = require "Unit.ViewControl.GainBias"
local ply = app.SECTION_PLY

local PassThru = Class {}
PassThru:include(Unit)

function PassThru:init(args)
    args.title = "PassThru"
    args.mnemonic = "--"
    Unit.init(self, args)
end

function PassThru:onLoadGraph(channelCount)
    local passthru = self:addObject("passthru", libPassThru.PassThru())
    local index = self:addObject("index",app.ParameterAdapter())
    local indexRange = self:addObject("indexRange",app.MinMax())
    self:addMonoBranch("index", index, "In", index, "Out")
    connect(self, "In1", passthru, "In")
    connect(index,"Out",indexRange,"In")
    tie(passthru, "Index", index, "Out")
    connect(passthru,"Out", self, "Out1")
    if channelCount > 1 then
        connect(passthru, "Out", self, "Out2")
    end
end

local views = {
    expanded = {"index","circle"},
    collapsed = {},
    input = {}
}

function PassThru:onLoadViews(objects, branches)
    local controls = {}

    controls.index = GainBias {
        button = "index",
        description = "test",
        branch = branches.index,
        gainbias = objects.index,
        range = objects.indexRange,
        biasMap = indexMap,
        biasPrecision = 0,
        gainMap = indexMap,
        initialBias = 0,
      }

      controls.circle = libPassThru.PassThruGraphic {
        --sequencer = objects.euclid
        bottom = 0,
        left = 0,
        width = 20,
        height = 20
      }

    return controls, views
end

local menu = {"infoHeader", "rename", "load", "save", "edit"}

return PassThru
