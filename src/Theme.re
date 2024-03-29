open Revery;
open Revery.UI;

type t =
  | Primary
  | Secondary;

module Colors = {
  let white = Color.hex("#ffffff");
  let black = Color.hex("#000000");
  let lightGrey = Color.hex("#e3f2fd");
  let grey = Color.hex("#e6ecf0");
  let lightBlue = Color.hex("#1da1f2");
  let blue = Color.hex("#4287f5");
};

module Spacing = {
  let xxs = 1;
  let xs = 2;
  let s = 4;
  let m = 8;
  let l = 16;
  let xl = 24;
  let xxl = 32;
  let xxxl = 49;
};