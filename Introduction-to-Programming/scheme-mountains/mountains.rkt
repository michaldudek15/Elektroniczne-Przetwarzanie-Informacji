#lang racket
(require 2htdp/image)

; Michał Dudek
; Maja Flaczek
; 7 marca 2023
; żeby narysować należy wpisać start

(define (warstwa1 n)
  (let ( [m (- n 1) ]
         [losowa_wielkosc (random 250)])
    (if (= n 1)
        (triangle losowa_wielkosc "solid" "black")
        (beside/align "bottom" (warstwa1 m) (warstwa1 m)))))

(define (warstwa2 n)
  (let ( [m (- n 1) ]
         [losowa_wielkosc (random 250)])
    (if (= n 1)
        (triangle losowa_wielkosc "solid" "gray")
        (beside/align "bottom" (warstwa2 m) (warstwa2 m)))))

(define (warstwa3 n)
  (let ( [m (- n 1) ]
         [losowa_wielkosc (random 250)])
    (if (= n 1)
            (triangle losowa_wielkosc "solid" "white")
        (beside/align "bottom" (warstwa3 m) (warstwa3 m)))))

(define sky (rectangle 1400 270 "solid" "lightblue"))
(define grass (rectangle 1400 20 "solid" "darkgreen"))
(define dirt (rectangle 1400 30 "solid" "lightbrown"))

(define start (above (overlay/align "center" "bottom" (warstwa1 4) (warstwa2 4) (warstwa3 4) sky) grass dirt))