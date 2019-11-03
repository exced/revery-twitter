open Revery;
open Revery.UI;
open Revery.UI.Components;

module Styles = {
  let scrollContainer = Style.[flexGrow(1)];
};

let component = React.component("Home");

let make = (~tweets, ()) =>
  component(hooks => {
    let tweets = List.map((tweet: Data.tweet) => <Tweet tweet />, tweets);

    (
      hooks,
      <ScrollView style=Styles.scrollContainer> ...tweets </ScrollView>,
    );
  });

let createElement = (~children as _, ~tweets, ()) => make(~tweets, ());