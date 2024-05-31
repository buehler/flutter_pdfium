import 'package:fluorflow/annotations.dart';
import 'package:fluorflow/fluorflow.dart';
import 'package:flutter/material.dart';

import '../app.router.dart';

@Routable(
  routeBuilder: RouteBuilder.platform,
)
class HomeView extends StatelessWidget {
  const HomeView({super.key});

  @override
  Widget build(BuildContext context) => Scaffold(
        appBar: AppBar(
          title: const Text('Flutter PDFium Example App'),
        ),
        body: ListView(
          children: [
            ListTile(
              leading:
                  const Icon(Icons.picture_as_pdf, color: Colors.deepOrange),
              title: const Text('Load PDF'),
              subtitle: const Text(
                  'Load a PDF file from memory and display its pages in a scrollable list'),
              onTap: locator<NavigationService>().navigateToInMemoryView,
            ),
            ListTile(
              leading: const Icon(Icons.bookmark, color: Colors.deepOrange),
              title: const Text('Bookmarks'),
              subtitle:
                  const Text('Show the document outline (bookmarks) of a PDF'),
              onTap: locator<NavigationService>().navigateToBookmarksView,
            ),
          ],
        ),
      );
}
