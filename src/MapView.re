module MapView = {
  [@bs.module "expo"] external mapView : ReasonReact.reactClass = "MapView";

  [@bs.deriving abstract]
  type region = {
    latitude: float,
    longitude: float,
    latitudeDelta: float,
    longitudeDelta: float,
  };

  [@bs.deriving abstract]
  type latlng = {
    latitude: float,
    longitude: float,
  };

  [@bs.deriving abstract]
  type location = {
    latitude: float,
    longitude: float,
    altitude: float,
    timestamp: float,
    accuracy: float,
    altitudeAccuracy: float,
    speed: float,
  };

  [@bs.deriving abstract]
  type point = {
    x: float,
    y: float,
  };

  [@bs.deriving abstract]
  type edgePadding = {
    top: float,
    right: float,
    bottom: float,
    left: float,
  };

  [@bs.deriving abstract]
  type edgeInsets = {
    top: float,
    right: float,
    bottom: float,
    left: float,
  };

  [@bs.deriving abstract]
  type marker = {
    id: string,
    coordinate: latlng,
    title: string,
    description: string,
  };

  [@bs.deriving abstract]
  type kmlContainer = {markers: array(marker)};

  type mapType =
    | Standard
    | None
    | Satellite
    | Hybrid
    | Terrain
    | MutedStandard;

  let fromMapTypeToString =
    fun
    | Standard => "standard"
    | None => "none"
    | Satellite => "satellite"
    | Hybrid => "hybrid"
    | Terrain => "terrain"
    | MutedStandard => "mutedStandard";

  type paddingAdjustmentBehavior =
    | Always
    | Automatic
    | Never;

  let fromPaddingAdjustmentBehaviorToString =
    fun
    | Always => "always"
    | Automatic => "automatic"
    | Never => "never";

  type customMapStyle;

  let make =
      (
        ~provider: option(string)=?,
        ~region: option(region)=?,
        ~initialRegion: option(region)=?,
        ~mapPadding: option(edgePadding)=?,
        ~paddingAdjustmentBehavior=Automatic,
        ~liteMode: option(bool)=?,
        ~mapType=Standard,
        ~customMapStyle: option(customMapStyle)=?,
        ~showsUserLocation: option(bool)=?,
        ~userLocationAnnotationTitle: option(string)=?,
        ~followsUserLocation: option(bool)=?,
        ~showsMyLocationButton: option(bool)=?,
        ~showsPointsOfInterest: option(bool)=?,
        ~showsCompass: option(bool)=?,
        ~showsScale: option(bool)=?,
        ~showsBuildings: option(bool)=?,
        ~showsTraffic: option(bool)=?,
        ~showsIndoors: option(bool)=?,
        ~showsIndoorLevelPicker: option(bool)=?,
        ~zoomEnabled: option(bool)=?,
        ~zoomControlEnabled: option(bool)=?,
        ~minZoomLevel: option(int)=?,
        ~maxZoomLevel: option(int)=?,
        ~rotateEnabled: option(bool)=?,
        ~scrollEnabled: option(bool)=?,
        ~pitchEnabled: option(bool)=?,
        ~toolbarEnabled: option(bool)=?,
        ~cacheEnabled: option(bool)=?,
        ~loadingEnabled: option(bool)=?,
        ~loadingIndicatorColor: option(string)=?,
        ~loadingBackgroundColor: option(string)=?,
        ~moveOnMarkerPress: option(bool)=?,
        ~legalLabelInsets: option(edgeInsets)=?,
        ~kmlSrc: option(string)=?,
        ~onMapReady: option(unit => unit)=?,
        ~onKmlReady: option(kmlContainer => unit)=?,
        ~onRegionChange: option(region => unit)=?,
        ~onRegionChangeComplete: option(region => unit)=?,
        ~onUserLocationChange: option({. "coordinate": location} => unit)=?,
        ~onPress:
           option(
             {
               .
               "coordinate": latlng,
               "position": point,
             } =>
             unit,
           )=?,
        ~onPanDrag:
           option(
             {
               .
               "coordinate": latlng,
               "position": point,
             } =>
             unit,
           )=?,
        ~onPoiClick:
           option(
             {
               .
               "coordinate": latlng,
               "position": point,
               "placeId": string,
               "name": string,
             } =>
             unit,
           )=?,
        ~onLongPress:
           option(
             {
               .
               "coordinate": latlng,
               "position": point,
             } =>
             unit,
           )=?,
        ~onMarkerPress: option(unit => unit)=?,
        ~onMarkerSelect: option(unit => unit)=?,
        ~onMarkerDeselect: option(unit => unit)=?,
        ~onCalloutPress: option(unit => unit)=?,
        ~onMarkerDragStart:
           option(
             {
               .
               "coordinate": latlng,
               "position": point,
             } =>
             unit,
           )=?,
        ~onMarkerDrag:
           option(
             {
               .
               "coordinate": latlng,
               "position": point,
             } =>
             unit,
           )=?,
        ~onMarkerDragEnd:
           option(
             {
               .
               "coordinate": latlng,
               "position": point,
             } =>
             unit,
           )=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=mapView,
      ~props=
        Js.Nullable.(
          {
            "provider": fromOption(provider),
            "region": fromOption(region),
            "initialRegion": fromOption(initialRegion),
            "mapPadding": fromOption(mapPadding),
            "paddingAdjustmentBehavior":
              fromPaddingAdjustmentBehaviorToString(
                paddingAdjustmentBehavior,
              ),
            "liteMode": fromOption(liteMode),
            "mapType": fromMapTypeToString(mapType),
            "customMapStyle": fromOption(customMapStyle),
            "showsUserLocation": fromOption(showsUserLocation),
            "userLocationAnnotationTitle":
              fromOption(userLocationAnnotationTitle),
            "followsUserLocation": fromOption(followsUserLocation),
            "showsMyLocationButton": fromOption(showsMyLocationButton),
            "showsPointsOfInterest": fromOption(showsPointsOfInterest),
            "showsCompass": fromOption(showsCompass),
            "showsScale": fromOption(showsScale),
            "showsBuildings": fromOption(showsBuildings),
            "showsTraffic": fromOption(showsTraffic),
            "showsIndoors": fromOption(showsIndoors),
            "showsIndoorLevelPicker": fromOption(showsIndoorLevelPicker),
            "zoomEnabled": fromOption(zoomEnabled),
            "zoomControlEnabled": fromOption(zoomControlEnabled),
            "minZoomLevel": fromOption(minZoomLevel),
            "maxZoomLevel": fromOption(maxZoomLevel),
            "rotateEnabled": fromOption(rotateEnabled),
            "scrollEnabled": fromOption(scrollEnabled),
            "pitchEnabled": fromOption(pitchEnabled),
            "toolbarEnabled": fromOption(toolbarEnabled),
            "cacheEnabled": fromOption(cacheEnabled),
            "loadingEnabled": fromOption(loadingEnabled),
            "loadingIndicatorColor": fromOption(loadingIndicatorColor),
            "loadingBackgroundColor": fromOption(loadingBackgroundColor),
            "moveOnMarkerPress": fromOption(moveOnMarkerPress),
            "legalLabelInsets": fromOption(legalLabelInsets),
            "kmlSrc": fromOption(kmlSrc),
            "onMapReady": fromOption(onMapReady),
            "onKmlReady": fromOption(onKmlReady),
            "onRegionChange": fromOption(onRegionChange),
            "onRegionChangeComplete": fromOption(onRegionChangeComplete),
            "onUserLocationChange": fromOption(onUserLocationChange),
            "onPress": fromOption(onPress),
            "onPanDrag": fromOption(onPanDrag),
            "onPoiClick": fromOption(onPoiClick),
            "onLongPress": fromOption(onLongPress),
            "onMarkerPress": fromOption(onMarkerPress),
            "onMarkerSelect": fromOption(onMarkerSelect),
            "onMarkerDeselect": fromOption(onMarkerDeselect),
            "onCalloutPress": fromOption(onCalloutPress),
            "onMarkerDragStart": fromOption(onMarkerDragStart),
            "onMarkerDrag": fromOption(onMarkerDrag),
            "onMarkerDragEnd": fromOption(onMarkerDragEnd),
          }
        ),
      children,
    );
};