#Gearing

##Tilter Gearing
- 'Partial' Tile Gear: 13
- Spur: 11
- REMEMBER THIS IS A NON STEPPER... (Should change to stepper? Will it fit?)

##Panner Gearing
- Outer: 97
- Spur: 13
- Stepper: 2038 Steps / Rev
- Gear Radio: 97/13 = 7.46153846154
    - 2038 * (97/13) = 15206.6153846
        - @360 degrees from North: 360 / (2038 * (97/13)) = 0.0236739071 deg / step
        - per 3 steps roughly 0.07102 deg
            - Sounds like a good radio, note will get hot with long and fast traversals?