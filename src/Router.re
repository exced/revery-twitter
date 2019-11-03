open Revery;
open Revery.UI;
open Revery.UI.Components;

module Routes = {
  type t =
    | Home
    | Explore
    | Notifications
    | Messages
    | Bookmarks
    | Lists
    | Profile
    | More;
};