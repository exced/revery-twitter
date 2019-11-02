open Revery;
open Revery.UI;
open Revery.UI.Components;

module Styles = {
  let container = Style.[minWidth(200), paddingTop(Theme.Spacing.xxl)];
};

let component = React.component("Sidebar");

let make = (~setRoute, ~currentRoute, ()) =>
  component(hooks => {
    (
      hooks,
      Router.(
        <View style=Styles.container>
          <ThemedButton
            kind=Theme.Secondary
            text="Home"
            centered=false
            active={currentRoute == Routes.Home}
            onClick={() => setRoute(Routes.Home)}
          />
          <ThemedButton
            kind=Theme.Secondary
            text="Explore"
            centered=false
            onClick={() => print_endline("TODO")}
          />
          <ThemedButton
            kind=Theme.Secondary
            text="Notifications"
            centered=false
            onClick={() => print_endline("TODO")}
          />
          <ThemedButton
            kind=Theme.Secondary
            text="Messages"
            centered=false
            onClick={() => print_endline("TODO")}
          />
          <ThemedButton
            kind=Theme.Secondary
            text="Bookmarks"
            centered=false
            onClick={() => print_endline("TODO")}
          />
          <ThemedButton
            kind=Theme.Secondary
            text="Lists"
            centered=false
            onClick={() => print_endline("TODO")}
          />
          <ThemedButton
            kind=Theme.Secondary
            text="Profile"
            centered=false
            active={currentRoute == Routes.Profile}
            onClick={() => setRoute(Routes.Profile)}
          />
          <ThemedButton
            kind=Theme.Secondary
            text="More"
            centered=false
            onClick={() => print_endline("TODO")}
          />
          <ThemedButton
            kind=Theme.Primary
            text="Tweet"
            onClick={() => print_endline("TODO")}
          />
        </View>
      ),
    )
  });

let createElement = (~children as _, ~setRoute, ~currentRoute, ()) =>
  make(~setRoute, ~currentRoute, ());