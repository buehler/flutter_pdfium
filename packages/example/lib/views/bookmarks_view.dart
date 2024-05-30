import 'package:fluorflow/annotations.dart';
import 'package:fluorflow/fluorflow.dart';
import 'package:flutter/material.dart';
import 'package:flutter_pdfium/flutter_pdfium.dart';

import 'bookmarks_viewmodel.dart';

@Routable(
  routeBuilder: RouteBuilder.platform,
)
final class BookmarksView extends FluorFlowView<BookmarksViewModel> {
  const BookmarksView({super.key});

  @override
  Widget builder(
          BuildContext context, BookmarksViewModel viewModel, Widget? child) =>
      Scaffold(
        appBar: AppBar(
          title: const Text('Bookmarks Example'),
        ),
        body: Column(
          children: [
            const Text('Show the bookmarks (document outline) of a PDF.'),
            const SizedBox(height: 16),
            const SizedBox(height: 8),
            const Divider(),
            const SizedBox(height: 8),
            Expanded(
              child: ListenableBuilder(
                  listenable: viewModel.dataNotifier,
                  builder: (context, _) =>
                      switch ((viewModel.busy, viewModel.data)) {
                        (true, _) => const CircularProgressIndicator(),
                        (_, final Document doc) => SingleChildScrollView(
                            child: Column(
                              children: [
                                for (final bookmark in doc.bookmarks)
                                  ListTile(
                                    title: Text(
                                        '${List.filled(bookmark.depth, '-').join()}${bookmark.title}'),
                                    subtitle: Text(
                                        'Page ${bookmark.pageIndex + 1} (@ ${bookmark.depth} level)'),
                                  ),
                              ],
                            ),
                          ),
                        _ => const Text('No document loaded'),
                      }),
            )
          ],
        ),
      );

  @override
  BookmarksViewModel viewModelBuilder(BuildContext context) =>
      BookmarksViewModel();
}
