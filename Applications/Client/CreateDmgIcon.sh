#!/bin/sh

# adapted from http://www.imagico.de/pov/icons.html

SCENE=pvDmgIcon.pov
IMAGE=pvDmgIcon
OPTIONS="-i${SCENE} +H512 +W512:q -D +fn"

convert -background black -fill white -font "Myriad-Pro-Semibold-Italic" -pointsize 72 label:ParaView -blur 25 label.png

povray $OPTIONS -o${IMAGE}_alpha.png DECLARE=Variant=1 +ua
povray $OPTIONS -o${IMAGE}_bkg.png DECLARE=Variant=2
povray $OPTIONS -o${IMAGE}_shadow.png DECLARE=Variant=3

convert -channel R -separate ${IMAGE}_bkg.png ${IMAGE}_r.png
convert -channel G -separate ${IMAGE}_bkg.png ${IMAGE}_g.png
convert -channel B -separate ${IMAGE}_bkg.png ${IMAGE}_b.png
convert -depth 8 -channel RGBA -combine ${IMAGE}_r.png ${IMAGE}_g.png ${IMAGE}_b.png ${IMAGE}_shadow.png ${IMAGE}_bkg2.png
composite -depth 8 -compose over ${IMAGE}_alpha.png ${IMAGE}_bkg2.png ${IMAGE}.png

rm -f ${IMAGE}_bkg2.png ${IMAGE}_r.png ${IMAGE}_g.png ${IMAGE}_b.png ${IMAGE}_bkg.png ${IMAGE}_alpha.png ${IMAGE}_shadow.png label.png
