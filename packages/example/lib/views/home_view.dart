import 'package:fluorflow/annotations.dart';
import 'package:fluorflow/fluorflow.dart';
import 'package:flutter/material.dart';

import '../app.router.dart';
import '../example.screens.dart';
import '../widgets/usecase_card.dart';

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
        body: LayoutBuilder(
            builder: (context, constraints) => GridView.count(
                  padding: const EdgeInsets.all(16),
                  crossAxisCount:
                      responsiveValue(1, context: context, sm: 2, lg: 2, xl: 3),
                  children: [
                    UseCaseCard(
                      icon: Icons.picture_as_pdf,
                      title: 'Load PDF',
                      description:
                          'Load a PDF file from memory and display its pages in a scrollable list',
                      onTap:
                          locator<NavigationService>().navigateToInMemoryView,
                    ),
                    UseCaseCard(
                      icon: Icons.bookmark,
                      title: 'Bookmarks',
                      description:
                          'Show the document outline (bookmarks) of a PDF',
                      onTap:
                          locator<NavigationService>().navigateToBookmarksView,
                    ),
                  ],
                )),
      );
}
