open Revery;
open Revery.UI;
open Revery.UI.Components;

module Routes = {
  type t =
    | Home
    | Profile
    | Tweet(string);
};