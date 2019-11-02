open Revery;
open Revery.UI;
open Revery.UI.Components;

module Styles = {};

let component = React.component("Home");

let make = () =>
  component(hooks => {
    let tweets =
      List.map((t: Tweet.tweet) => <Tweet id={t.tweet_id} />, Tweet.tweets);

    (hooks, <View> ...tweets </View>);
  });

let createElement = (~children as _, ()) => make();