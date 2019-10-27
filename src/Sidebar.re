open Revery;
open Revery;
open Revery.UI;
open Revery.UI.Components;

module Styles = {
  let scrollContainer =
    Style.[position(`Absolute), top(0), left(0), width(175), bottom(0)];
};

let component = React.component("Sidebar");

let make = (~setRoute, ~currentRoute, ()) =>
  component(hooks =>
    (
      hooks,
      Router.(
        <ScrollView style=Styles.scrollContainer>
          <Link
            active={currentRoute == Routes.Home}
            onClick={() => setRoute(Routes.Home)}
            text="Home"
          />
          <Link
            active={currentRoute == Routes.Profile}
            onClick={() => setRoute(Routes.Profile)}
            text="New"
          />
        </ScrollView>
      ),
    )
  );

let createElement = (~children as _, ~setRoute, ~currentRoute, ()) =>
  make(~setRoute, ~currentRoute, ());