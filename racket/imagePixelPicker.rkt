#lang racket

(require 2htdp/universe 2htdp/image picturing-programs)

(define PICTURE (bitmap "/Users/Ming/Desktop/4.png"))
(define HEIGHT (image-height PICTURE))
(define WIDTH  (image-width  PICTURE))

(define (color->string c)
  (format "(color ~a ~a ~a ~a)" (color-red c) (color-green c)
                                (color-blue c) (color-alpha c)))

;(define (do-color w x y k)
;  (define g (get-pixel-color x y PICTURE))
;  (when (mouse=? "button-down" k) (displayln (color->string g)))
;  g)

;(big-bang (color 255 255 255 0)
;          (to-draw (lambda (w) PICTURE))
;          (on-mouse do-color))

(define g (get-pixel-color 20 20 PICTURE))
(displayln (color->string g))