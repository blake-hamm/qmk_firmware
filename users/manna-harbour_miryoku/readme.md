# Commands
```bash
qmk list-keymaps -kb idank/spankbd

qmk compile -kb idank/spankbd -km manna-harbour_miryoku \
    -e MIRYOKU_ALPHAS=QWERTY \
    # -e MIRYOKU_EXTRA=COLEMAKDH \
    # -e MIRYOKU_TAP=QWERTY \
    -e MIRYOKU_NAV=INVERTEDT \
    # -e MIRYOKU_CLIPBOARD=WIN \
    # -e MIRYOKU_LAYERS=FLIP \
    
    # Hardware
    -e POINTING_DEVICE=trackpoint \
    -e POINTING_DEVICE_POSITION=right \
    -e OLED=yes \
    -j20 # parallel

qmk flash -kb idank/spankbd -km manna-harbour_miryoku \
    -e MIRYOKU_ALPHAS=QWERTY \
    -e POINTING_DEVICE=trackpoint \
    -e POINTING_DEVICE_POSITION=right \
    -e OLED=yes
    
qmk flash -kb idank/spankbd -km manna-harbour_miryoku \
    -e MIRYOKU_ALPHAS=QWERTY \
    -e POINTING_DEVICE=trackpoint \
    -e POINTING_DEVICE_POSITION=right \
    -e MIRYOKU_CLIPBOARD=MAC \
    -e OLED=yes
```
