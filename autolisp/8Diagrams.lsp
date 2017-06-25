(defun C:8d()
    (setq osmd (getvar "osmode")) (setq colr (getvar "cecolor"))
    (setq cen (getpoint "POSITION: "))
    (setq rad (getreal "RADIUS: "))
    (setvar "CEcolor" "green")
    (command "pline" (polar cen (/ pi 2) rad) "a"  cen 
        (polar cen (/ (* pi 3) 2) rad) (polar cen (/ pi 2) rad) "cl")
    (command "hatch" "solid" "L" "")
    (setvar "CEcolor" "blue")
    (command "pline" (polar cen (/ (* pi 3) 2) rad) "a" cen
        (polar cen (/ pi 2) rad) (polar cen (/ (* pi 3) 2) rad) "cl")
    (command "hatch" "solid" "L" "")
    (command "circle" (polar cen (/ (* pi 3) 2) (/ rad 2)) (/ rad 4))
    (command "hatch" "solid" "L" "")
    (setvar "CEcolor" "green")
    (command "circle" (polar cen (/ pi 2) (/ rad 2)) (/ rad 4))
    (command "hatch" "solid" "L" "")
    (setvar "osmode" osmd) (setvar "cecolor" colr)
)