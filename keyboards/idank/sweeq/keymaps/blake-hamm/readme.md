# Blake Hamm config

Configure here - https://config.qmk.fm/#/idank/sweeq/LAYOUT_split_3x5_2
Discord - https://discord.com/channels/1143602022432641044/1267625056998264883

```bash
# To convert to json
qmk json2c \
  keyboards/idank/sweeq/keymaps/blake-hamm/idank_sweeq_blake-hamm.json \
  -o keyboards/idank/sweeq/keymaps/blake-hamm/keymap.c
  
# To json to c
qmk c2json \
  keyboards/idank/sweeq/keymaps/blake-hamm/keymap.c \
  -o keyboards/idank/sweeq/keymaps/blake-hamm/idank_sweeq_blake-hamm.json

# To make
make idank/sweeq:blake-hamm:flash \
  -e TARGET=blake-hamm \
  -e USER_NAME=idank \
  -e POINTING_DEVICE=trackpoint_cirque40 \
  -e SIDE=right \
  -j20
  
# To make with one device
make idank/sweeq:blake-hamm:flash \
    -e TARGET=blake-hamm \
    -e USER_NAME=idank \
    -e POINTING_DEVICE=cirque40 \
    -e POINTING_DEVICE_POSITION=right \
    -j20
```
