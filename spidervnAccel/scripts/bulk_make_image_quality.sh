#!/bin/bash

for FILE in *
do
	if [ -d "$FILE" ]
	then
		#echo "$FILE A DIRECTORY"
		cp make_image_quality.sh "$FILE"
		cd "$FILE"
		./make_image_quality.sh
		cd ..
	fi
done

idx="0"
for FILE in *
do
        if [ -f "$FILE" ] && (echo "$FILE" | grep --ignore-case ".jpg$"  > /dev/null || echo "$FILE" | grep --ignore-case ".png$" > /dev/null || echo "$FILE" | grep --ignore-case ".gif$")
        then
                if [ $idx -eq 0 ];
                then
                        # Resize grid avatar (1st file)
                        echo $grid_avatar_dimension
                        convert "$FILE" -resize $grid_avatar_dimension "000_gridavatar_$FILE"
                else
                        # Resize detail avatar (>=2nd file)
                        convert "$FILE" -resize $detail_avatar_dimension "001_gridavatar_$FILE"
                fi
                idx=$((idx+1))
        fi
done