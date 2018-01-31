#!/bin/bash

resizedir_normal=normal_quality
resizedir_good=good_quality
resizedir_high=high_quality
comicinfo_dir=comic

maxpixel_normal=1200000
maxpixel_good=1500000
maxpixel_high=6000000
grid_avatar_dimension="205x305"
detail_avatar_dimension="303x403"

mkdir $resizedir_normal
mkdir $resizedir_good
mkdir $resizedir_high
mkdir $comicinfo_dir

found_avatar0=0
found_avatar1=0
avatar0=""

IMGFILES="*.jpg
*.JPG"

for FILE in *
do
	if [ -f "$FILE" ] && (echo "$FILE" | grep --ignore-case ".jpg$"  > /dev/null || echo "$FILE" | grep --ignore-case ".png$" > /dev/null || echo "$FILE" | grep --ignore-case ".gif$")
	then
		echo "Starting resizing $FILE"

		myw=$(identify -format %w "$FILE")
		myh=$(identify -format %h "$FILE")
		
		totalpixel=$(($myw*$myh))

		echo "$myw x $myh = $totalpixel"

		# Only resize if total_pixel >= target
		if test $totalpixel -ge $maxpixel_normal; then
			echo "Larger - resize (normal)"
			convert "$FILE" -resize $maxpixel_normal@ "$resizedir_normal/resize_$FILE"
		else
			echo "Not larger  (normal)"
			cp "$FILE" "$resizedir_normal/resize_$FILE"
		fi 	
		 
		if test $totalpixel -ge $maxpixel_good; then
			echo "Larger - resize (good)"
			convert "$FILE" -resize $maxpixel_good@ "$resizedir_good/resize_$FILE"
		else
			echo "Not larger (good)"
			cp "$FILE" "$resizedir_good/resize_$FILE"
		fi 	

		if test $totalpixel -ge $maxpixel_high; then
			echo "Larger - resize (high)"
			convert "$FILE" -resize $maxpixel_high@ "$resizedir_high/resize_$FILE"
		else
			echo "Not larger (high)"
			cp "$FILE" "$resizedir_high/resize_$FILE"
		fi 	

		# If portrait image => use it for avatar image
		if [ $myh -ge $myw ] && [ $found_avatar0 -eq 0 ]; then
			found_avatar0=1
			avatar0=$FILE
			convert "$FILE" -resize $grid_avatar_dimension "$comicinfo_dir/000_gridavatar_$FILE"
		elif [ $myh -ge $myw ] && [ $found_avatar0 -eq 1 ] && [ $found_avatar1 -eq 0 ]; then
		 	found_avatar1=1
		 	convert "$FILE" -resize $detail_avatar_dimension "$comicinfo_dir/001_gridavatar_$FILE"
		fi
		
		#convert "$FILE" -resize $maxpixel_normal@ "$resizedir_normal/resize_$FILE"
		#convert "$FILE" -resize $maxpixel_good@ "$resizedir_good/resize_$FILE"
		#convert "$FILE" -resize $maxpixel_high@ "$resizedir_high/resize_$FILE"
		echo "Finished $FILE"
	fi
done

# Still not found Avatar1? => Use Avatar 0
if [ $found_avatar1 -eq 0 ] && [ $found_avatar0 -eq 1 ]; then
	convert "$avatar0" -resize $detail_avatar_dimension "$comicinfo_dir/001_gridavatar_$avatar0"	
fi

#convert Age\ of\ Ultron10AI-002.jpg -family Tahoma -pointsize 180  -gravity center -fill "rgba(0,0,255,0.2)" -annotate 45 'truyenspiderman.vn' xxx.bmp
 
