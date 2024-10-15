```bash
make idank/spankbd:default:flash \
    -e TARGET=default \
    -e USER_NAME=idank \
    -e POINTING_DEVICE=trackpoint \
    -e POINTING_DEVICE_POSITION=right \
    -e OLED=yes \
    -j20
# Or
qmk compile -kb idank/spankbd -km default \
    -e TARGET=default \
    -e USER_NAME=idank \
    -e POINTING_DEVICE=trackpoint \
    -e POINTING_DEVICE_POSITION=right \
    -e OLED=yes \
    -j20
```
