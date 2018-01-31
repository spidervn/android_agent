#!/bin/bash

crop_dir=crop_dir

mkdir $crop_dir

IMGFILES="*.jpg
*.JPG"

for FILE in *
do
	if [ -f "$FILE" ] && (echo "$FILE" | grep --ignore-case ".jpg$"  > /dev/null || echo "$FILE" | grep --ignore-case ".png$" > /dev/null || echo "$FILE" | grep --ignore-case ".gif$")
	then
		echo "Starting resizing $FILE"

		myw=$(identify -format %w "$FILE")
		myh=$(identify -format %h "$FILE")

		myw_2=$((myw/2))
		myh_2=$((myh/2))

		myw_2_plus50=$((myw_2+50))
		myh_2_plus50=$((myh_2+50))

		myw_2_minus50=$((myw_2-50))
		myh_2_minus50=$((myh_2-50))

		totalpixel=$(($myw*$myh))

		echo "$myw x $myh = $totalpixel"

		# Only resize if total_pixel >= target
		# if test $totalpixel -ge $maxpixel_normal; then
		# 	echo "Larger - resize (normal)"
		# 	convert "$FILE" -resize $maxpixel_normal@ "$resizedir_normal/resize_$FILE"
		# else
		# 	echo "Not larger  (normal)"
		# 	cp "$FILE" "$resizedir_normal/resize_$FILE"
		# fi 	
		 
		# if test $totalpixel -ge $maxpixel_good; then
		# 	echo "Larger - resize (good)"
		# 	convert "$FILE" -resize $maxpixel_good@ "$resizedir_good/resize_$FILE"
		# else
		# 	echo "Not larger (good)"
		# 	cp "$FILE" "$resizedir_good/resize_$FILE"
		# fi 	

		# if test $totalpixel -ge $maxpixel_high; then
		# 	echo "Larger - resize (high)"
		# 	convert "$FILE" -resize $maxpixel_high@ "$resizedir_high/resize_$FILE"
		# else
		# 	echo "Not larger (high)"
		# 	cp "$FILE" "$resizedir_high/resize_$FILE"
		# fi 	
		filename=$(basename "$FILE")
		echo $filename
		file_ext="${filename##*.}"
		echo $file_ext
		filename="${filename%.*}" 
		echo $filename

		echo "$crop_dir/${filename}_part1.$file_ext"
		convert "$FILE" -crop ${myw_2_plus50}x${myh_2_plus50}+0+0 "$crop_dir/${filename}_part1.$file_ext"
		convert "$FILE" -crop ${myw_2_plus50}x${myh_2_plus50}+$myw_2_minus50+0 "$crop_dir/${filename}_part2.$file_ext"
		convert "$FILE" -crop ${myw_2_plus50}x${myh_2_plus50}+0+$myh_2_minus50 "$crop_dir/${filename}_part3.$file_ext"
		convert "$FILE" -crop ${myw_2_plus50}x${myh_2_plus50}+$myw_2_minus50+$myh_2_minus50 "$crop_dir/${filename}_part4.$file_ext"
		
		#convert "$FILE" -resize $maxpixel_normal@ "$resizedir_normal/resize_$FILE"
		#convert "$FILE" -resize $maxpixel_good@ "$resizedir_good/resize_$FILE"
		#convert "$FILE" -resize $maxpixel_high@ "$resizedir_high/resize_$FILE"
		echo "Finished $FILE"
	fi
done

#convert Age\ of\ Ultron10AI-002.jpg -family Tahoma -pointsize 180  -gravity center -fill "rgba(0,0,255,0.2)" -annotate 45 'truyenspiderman.vn' xxx.bmp
 
