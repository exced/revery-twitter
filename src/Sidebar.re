open Revery;
open Revery.UI;
open Revery.UI.Components;

module Styles = {
  let container =
    Style.[
      minWidth(200),
      paddingTop(Theme.Spacing.xxl),
      marginRight(Theme.Spacing.l),
    ];
};

let component = React.component("Sidebar");

let make = (~setRoute, ~currentRoute, ~toggleTweetInput, ()) =>
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
            active={currentRoute == Routes.Explore}
            onClick={() => setRoute(Routes.Explore)}
          />
          <ThemedButton
            kind=Theme.Secondary
            text="Notifications"
            centered=false
            active={currentRoute == Routes.Notifications}
            onClick={() => setRoute(Routes.Notifications)}
          />
          <ThemedButton
            kind=Theme.Secondary
            text="Messages"
            centered=false
            active={currentRoute == Routes.Messages}
            onClick={() => setRoute(Routes.Messages)}
          />
          <ThemedButton
            kind=Theme.Secondary
            text="Bookmarks"
            centered=false
            active={currentRoute == Routes.Bookmarks}
            onClick={() => setRoute(Routes.Bookmarks)}
          />
          <ThemedButton
            kind=Theme.Secondary
            text="Lists"
            centered=false
            active={currentRoute == Routes.Lists}
            onClick={() => setRoute(Routes.Lists)}
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
            active={currentRoute == Routes.More}
            onClick={() => setRoute(Routes.More)}
          />
          <ThemedButton
            kind=Theme.Primary
            text="Tweet"
            onClick=toggleTweetInput
          />
        </View>
      ),
    )
  });

let createElement =
    (~children as _, ~setRoute, ~currentRoute, ~toggleTweetInput, ()) =>
  make(~setRoute, ~currentRoute, ~toggleTweetInput, ());