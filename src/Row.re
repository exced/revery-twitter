open Revery;
open Revery.UI;
open Revery.UI.Components;

module Styles = {
  let container = Style.[flexDirection(`Row)];
};

let component = React.component("Profile");

let make = (~children, ()) =>
  component(hooks => (hooks, <View style=Styles.container> children </View>));

let createElement = (~children, ()) => make(~children, ());